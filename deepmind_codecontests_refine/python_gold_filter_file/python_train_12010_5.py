n=int(input())
l=sorted(list(set(list(map(int,input().split())))))
print('NO' if len(l)<=1 else l[1])