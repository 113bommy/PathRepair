m=(int(input())-1)//2
k=l=0
for x in map(int,input().split()):k+=x>0;l+=x<0
print(1 if k>m else -1if l>m else 0)