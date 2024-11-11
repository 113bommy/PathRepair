from itertools import combinations as f
l,r=map(int,input().split())
s=set(map(lambda x:x%2019,range(l,r+1)[:2019]))
print(min([i*j%2019 for i,j in f(s,2)]))