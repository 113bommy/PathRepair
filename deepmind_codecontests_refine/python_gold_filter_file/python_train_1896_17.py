no_testcases=int(input())
numlist=list(map(int,input().split()))
for number in numlist:
     if(number%14>=1 and number%14<=6 and number>=15):
         print("YES")
     else:
         print("NO")
         