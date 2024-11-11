n=int(input())
k=-1
l=input()
for i in range(len(l)+1):
    s=l[:i].count('0')+l[i:].count('1')
    if(s>k):
        k=s
print(k)
