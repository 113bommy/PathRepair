n = int(input())
 
bn = bin(n)[2:]
bn = "0"*(6-len(bn))+bn
 
print(int(bn[0]+bn[5]+bn[3]+bn[2]+bn[4]+bn[1],2))