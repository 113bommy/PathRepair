s=input()
k=int(input())
l=set()
for i in  range(len(s)):
    for j in range(1,k+1):
        l.add(s[i:i+j])
ll=list(l)
ll.sort()

print(ll[k-1])
