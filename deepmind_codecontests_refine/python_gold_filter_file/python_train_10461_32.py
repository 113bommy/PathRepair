k,n,w=map(int,input().split(" "))
totalMoneyNeeded = ((w*(w+1)) * k)/2
print(int(max(totalMoneyNeeded - n, 0)))