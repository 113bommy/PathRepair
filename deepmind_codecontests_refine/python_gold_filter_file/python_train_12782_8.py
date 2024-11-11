import collections
N=int(input())
lst=input().split()
s=0
dic=collections.Counter(lst)
for i in dic.values():
    s+=(i*i-i)//2
for i in lst:
    print(s+1-dic[i])