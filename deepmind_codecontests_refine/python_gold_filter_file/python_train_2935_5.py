n=int(input())
for i in range(n):
    if i%2==0:
        curr='WB'*(n//2)+'WB'[:n%2]
    else:
        curr='BW'*(n//2)+'BW'[:n%2]
    print(curr)