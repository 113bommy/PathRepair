n=int(input())
l=[int(i) for i in input().split()]
l.sort()
curr=1 
for i in l:
    if i>=curr:
        curr+=1 
print(curr)