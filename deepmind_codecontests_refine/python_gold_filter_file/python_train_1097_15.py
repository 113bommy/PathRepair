a1=b1=c1=0
for _ in range(int(input())):
    a,b,c=[int(i) for i  in input().split()]
    a1+=a
    b1+=b
    c1+=c
if a1==0 and b1==0 and c1==0:
    print("YES")
else:
    print("NO")
