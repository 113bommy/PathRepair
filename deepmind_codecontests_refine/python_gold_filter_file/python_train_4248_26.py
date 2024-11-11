n=int(input())
if n%2==1:print(0)
else:
    sum=0
    for i in range(1,52):
        sum+=(n//(2*5**i))
    print(sum)