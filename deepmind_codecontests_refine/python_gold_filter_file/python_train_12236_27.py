import sys

'''
a -> b increasing number 
     -b decreasing number
'''
class walk:
    def __init__(self,house,start,distance):
        self.h = house
        self.s = start
        self.d = distance

    def calEnd(self):
        rem = (self.s + self.d)%self.h
        if rem == 0:
            return self.h
        return abs(rem)

def main():
    hou, start, dis = [int(x) for x in sys.stdin.readline().split()]
    w = walk(hou,start,dis)
    print(w.calEnd())

if __name__ == ("__main__"):
    main()
