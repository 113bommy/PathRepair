n=int(input())
st=[0]*2
for i in range(n):
    x,y=[int(i) for i in input().split(" ")]
    if x>=0 and y>=0 or x>=0 and y<=0:
        st[0]+=1
    elif x<=0 and y>=0 or x<=0 and y<=0:
        st[1]+=1
if st[0]<=1 or st[1]<=1:
    print("Yes")
else:
    print("No")