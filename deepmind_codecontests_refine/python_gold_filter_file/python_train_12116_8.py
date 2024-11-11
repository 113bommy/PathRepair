l,r=map(int,(input().split()))
for i in range(64,-2,-1):
    if(i<0 or ((1<<i)&l)!=((1<<i)&r)): break
print((1<<(i+1))-1)