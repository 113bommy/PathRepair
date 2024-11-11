n=int(input())
al=list(map(int,input().split()))

counter=[0]*(n+1)
for a in al:
    counter[a]+=1

sum=0
for c in counter:
    sum+=c*(c-1)//2

for a in al:
    print(sum-(counter[a]-1))
