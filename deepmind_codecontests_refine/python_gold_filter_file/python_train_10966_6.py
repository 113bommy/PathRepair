l1 = [int(x) for x in input().split()]
examnumber = l1[0]
totalscore = l1[1]
print(max(0,examnumber*3-totalscore))
