n, k = (map(int,input().split()))
a = list(map(int,input().split()))
sum = 0
negativeCount = 0
leastAbsoulute=10000

for i in range(0, n):
    if(abs(a[i]) < leastAbsoulute):
        leastAbsoulute = abs(a[i])
    if(a[i] < 0):
        negativeCount += 1
    sum += abs(a[i])

if k <= negativeCount:  #that means you need to convert the most k negative numbers
    for i in range(k, negativeCount):    #since we already sumed the absoulute of all value we need to
        sum += 2 * a[i]                    #subtract the values tat should have stayed negative (k --> firstNeg)
else:   #that means all negative numbers will be converted
    if (k - negativeCount)%2 != 0:     #if the no remaining conversions that must be made are even do nothing as (if he picks a pos number and keeps converting it) 
            sum -= 2*leastAbsoulute     #if it's odd then convert the least aboulute value (ie. subtract the least absoulutevalue from sum)


print(sum)