n = int(input())
bid = list(map(int,input().split((' '))))
i=bid.index(max(bid))
bid[i]=-1
m=max(bid)
print(i+1,m)