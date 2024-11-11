from itertools import combinations as f
l,r=map(int,input().split())
print(min([i*j%2019 for i,j in f(range(l,r+1)[:2019],2)]))