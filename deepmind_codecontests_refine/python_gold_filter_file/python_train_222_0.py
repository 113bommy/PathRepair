n=int(input())
l=input()
if n==1:
    print(1)
    print(l)
elif l.count('1')==0 or l.count('0')==0:
    print(1)
    print(l)
elif l.count('1')!=l.count('0'):
    print(1)
    print(l)
else:
    print(2)
    for i in range(len(l)-1,-1,-1):
        if l[i:].count('0')!=l[i:].count('1') and l[:i].count('1')!=l[:i].count('0'):
            print(l[:i],l[i:])
            break