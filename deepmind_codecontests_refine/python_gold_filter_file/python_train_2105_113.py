from collections import Counter
N=int(input())
arr=Counter(input())
ans=0
for key,value in arr.items():
    ans+=value
print(ans+1)