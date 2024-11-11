n = int(input())
s = str(input())
alist =[]
for i in range(n-1):
    alist.append(s[i]+s[i+1])
myset=set(alist)
mylist=list(myset)
for item in myset:
     if mylist.index(item)==0:
        a =alist.count(item)
        result = item

     else:
        new=alist.count(item)
        if a < new:
            a = new
            result = item

print(result)


