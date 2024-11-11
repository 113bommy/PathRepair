a,b,c,d=map(int,input().split())
ta=(c-1)//b+1
ao=(a-1)//d+1
print('Yes') if ta<=ao else print('No')