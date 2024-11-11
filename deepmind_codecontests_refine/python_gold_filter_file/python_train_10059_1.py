#import  numpy  as np
#import array as arr
#import math as m
s=input()
j=0;a=1;b=0;max1=0
if len(s)==1   :
    print(1)
elif len(s)==2 :
    print(2)
else :
    if s[0]=='a':j+=1
    if s[1] == 'a': j+=1
    if s[1] == 'b': b=1
    dp=[1,2]
    for i in range(2,len(s),1):
        if s[i]=='a':
            j+=1
            dp.append(max(dp[a]+1,dp[b]+1))
            a=i
        else:
            dp.append(max(j+1,dp[b]+1))
            b=i
        max1=max(max1,dp[i])
    print(max1)
