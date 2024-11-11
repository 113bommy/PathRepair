#!/usr/bin/env python
 
class HashMap(object):

    def __init__(self, size=256):
        # self._values = [None for item in range(size)]
        self._keys = []
        self.data = [[0] for i in range(size)]
        self.numItems = 0
        self.size = size
    
    # def __getitem__(self,key):
        # if self._values[self.hashfunc(key)] is not None:
        #     return self._values[self.hashfunc(key)] 
        # else:
        #     return None

    def __setitem__(self,key,value):
        
        pos = self.set_find(key) #find empty space or old value
        if pos != -1:
            if len(self.data[pos]) > 1:
                if self.data[pos][0] == key:
                    try:
                        self.data[pos] = [key, value]
                    except:
                        print("Update failed!")
                        return False
                    return True
            
            self.data[pos] = [key, value]
            self.numItems += 1
   
            self._keys.append(key)            
            return True
        else:
            return False
        # if value is None:
        #     raise ValueError('None is not permitted as a value.')

        # if self._values[self.hashfunc(key)] is None:
        #     self._keys.append(key)
        #     self._values[self.hashfunc(key)] = value
        #     # print(float(len(self._keys))/len(self._values))
        #     if (self.size - len(self._keys)) == 2:
        #     # if float(len(self._keys))/len(self._values) > 0.1:
        #         self.__resize__()
        
        # else:
        #     if key in self._keys: 
        #         self._values[self.hashfunc(key)] = value
        #     else:
        #         self._keys.append(key)
        #         self._values[self.hashfunc(key)] = value
        #         # self.__resize__() # resize values
        #         # self.__setitem__(key,value) 

    def __missing__(self,not_key):
        raise KeyError('{0} is not a valid key'.format(not_key))

    def __getitem__(self, key):
        pos = self.get_find(key)
        if pos == -1:
            return None
        else:
            return self.data[pos][1]

    def __repr__(self):
        # list_repr = ['{0}:{1}'.format(key, self._values[self.hashfunc(key)]) for key in self._keys]
        return str(self.data)
        return 'HashMap({0})'.format(list_repr)

    def __contains__(self,key):
        if key in self._keys:
            return True
        else:
            return False

    def __len__(self):
        return len(self._keys)

    def __iter__(self):
        return (key for key in self._keys)

    def hashfunc(self,key): # with collision
        print(hash(key))
        return hash(key) % len(self._values)

    def set_find(self, key):
        
        collisionNum = 0
        currentPos = hash(key) % self.size #hash key
        
        while self.data[currentPos][0] != 0 and self.data[currentPos][0]!=key:
            """quadratic resolution"""
            collisionNum += 1
            currentPos = (currentPos + collisionNum**2) % self.size
            """alternate way of calculating
            currentPos += 2*collisionNum - 1
            if currentPos >= self.capacity:
                currentPos -= self.capacity
            """
            if collisionNum > self.size:
                return -1 
                """this doesn't mean there aren't empty slots, but at this
                point you're better off rehashing"""
            
        return currentPos

    
    def get_find(self, key):
        collisionNum = 0
        currentPos = hash(key) % self.size #hash key
        while True:
            while self.data[currentPos][0] != 0 and self.data[currentPos][0]!=key:
                collisionNum += 1
                currentPos = (currentPos + collisionNum**2) % self.size
                if collisionNum > self.size:
                    return -1 
            if self.data[currentPos][0] == 0:
                if len(self.data[currentPos]) == 1:
                    return -1
                else:
                    collisionNum += 1
                    currentPos = (currentPos + collisionNum**2) % self.size
            else: #found key
                return currentPos 

    # def __resize__(self,**kwargs):
    #     old_values = kwargs.get('values',[self._values[self.hashfunc(key)] for key in self._keys])
    #     self._values = [None for item in range(2*len(self._values))]
    #     for key, value in zip(self._keys,old_values):
    #         if self._values[self.hashfunc(key)] is None: 
    #             self._values[self.hashfunc(key)] = value
    #         else:
    #             self.__resize__(values = old_values)


class Item:
        def __init__(self, key, value):
            self.key=key
            self.value=value

## do it using linear probing and two lists (for easier retrieval of keys and values ). Use Open addressing. Should support resizing

class hashTable:
    def __init__(self):
        self.arraysize=1000000
        self.itemsize=0
        self.itemarray=[-1]*self.arraysize


    def update(self,newsize):

        oldarray=self.itemarray
        oldsize=self.arraysize

        self.arraysize=newsize

        self.itemarray=[-1]*newsize

        self.itemsize=0

        for i in range(oldsize):
            if oldarray[i]!=-1:
                self.put(oldarray[i].key,oldarray[i].value)


    def put(self,key,value):

        if (self.itemsize+1)*3>=2*self.arraysize:
            self.update(self.arraysize*2)

        position=self.hashing(key)
        if self.itemarray[position]==-1:
            self.itemarray[position]=Item(key,value)
            self.itemsize=1+self.itemsize
            return
        else:
            nextposition=position
            count=1
            while True:
                if self.itemarray[nextposition]==-1:
                    self.itemarray[nextposition]=Item(key,value)
                    self.itemsize=1+self.itemsize
                    return
                elif self.itemarray[nextposition].key==key:
                    self.itemarray[nextposition].value=value
                    return

                nextposition=self.rehash(nextposition,count)
                count=count+1


    def rehash(self,hashvalue,count):

        return (hashvalue+count**2)%self.arraysize

    def hashing(self,key):

        return  hash(key)%(self.arraysize-1)


    def get(self,key):

        position=self.hashing(key)
        if self.itemarray[position]==-1:
            return None
        else:
            nextposition=position
            count=1
            while True:
                if self.itemarray[nextposition]==-1:
                    return None
                elif self.itemarray[nextposition].key==key:
                    return self.itemarray[position].value

                nextposition=self.rehash(nextposition,count)
                count=count+1


    def __getitem__(self,key):

        return self.get(key)

    def __setitem__(self,key,value):

        return self.put(key,value)

    def __len__(self):
        return self.itemsize

    def __contains__(self, key):
        return self.get(key)!=None

    def __delitem__(self, key):

        position=self.hashing(key)
        if self.itemarray[position]==-1:
            raise KeyError("%s does not exist" % key)
        else:
            nextposition=position
            count=1
            while True:
                if self.itemarray[nextposition]==-1:
                    raise KeyError("%s does not exist" % key)
                elif self.itemarray[nextposition].key==key:
                    self.itemarray[nextposition]=-1
                    self.itemsize=self.itemsize-1
                    return

                nextposition=self.rehash(nextposition,count)
                count=count+1

    def keys(self):
        for i in range(self.arraysize):
            if self.itemarray[i]!=-1:
                yield self.itemarray[i].key


    def values(self):
        for i in range(self.arraysize):
            if self.itemarray[i]!=-1:
                yield self.itemarray[i].value



if __name__ == '__main__':
    answer = 0
    min_val = 0
    diam = 0
    # with open("input.txt") as f_in:
    n = int(input())
    shapes = hashTable()
    # shapes = HashMap(400)
    for i in range(n):
        face = list(sorted(map(int, input().split())))
        key = (face[1], face[2])
        if key in shapes:

        # if shapes.get_find(key) != -1:
            # old, k = shapes[key]
            old, k = shapes[key]
            res = [old + face[0], face[1], face[2]]
            m = min(res)
            if m > min_val:
                min_val = m
                diam = m
                mn = [k, i]
            if old < face[0]: # update min
                # shapes.set(key, (face[0], i))
                shapes[key] = (face[0], i)
        else:      
            # shapes.set(key, (face[0], i))
            shapes[key] = (face[0], i)

            # shapes.insert(new_key)
        m = face[0]    
        if m > min_val:
            diam = min(face)
            min_val = m
            mn = [i]

    # with open('output.txt','w') as f_out:
    #     f_out.write(str(len(mn)) + "\n"\
    #     + " ".join(map(lambda x: str(x+1), mn)) + "\n" \
    #      + str(min_val))

    print(len(mn))
    print(" ".join(map(lambda x: str(x+1), mn)))   
    # print("diameter", min_val)  
              