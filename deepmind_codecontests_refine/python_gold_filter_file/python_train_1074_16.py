input();s=sorted(map(lambda x:int(x)**2,input().split()))
print(abs(sum(s[::2])-sum(s[1::2]))*3.1416)