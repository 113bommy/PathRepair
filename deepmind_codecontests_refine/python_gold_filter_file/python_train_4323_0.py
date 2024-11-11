#IN THE NAME OF GOD
a=int(input())
b=bin(a)
i=2
while i<len(b):
    if b[i]=='1':
        print( len(b)-i,end=" ")
    i+=1

