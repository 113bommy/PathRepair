l=list(map(int,input().split()))
ct=0
while l[0]<=l[1]:
    ct+=1
    l[0]*=3
    l[1]*=2
print(ct)