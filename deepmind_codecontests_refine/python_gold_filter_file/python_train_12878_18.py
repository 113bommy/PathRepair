n=int(input())
z=input().split()


l=set(map(int,z))
if 0 in l:
    l.remove(0)
    
print(len(l))
