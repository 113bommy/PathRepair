import sys
n = int(input())

grades = list(map(int,input().split()))
count = 0
produce = sum(grades)

result = produce/n

result1 = produce//n

if result>= 4.5:
    print('0')
    sys.exit()
else:
    result2 = (4.5-result)*n
grades.sort()
for i in grades:
    result3 = result2 - 5 + i
    
    if result3<=0.1:
        count +=1
        print(count)
        sys.exit()
    else:
        result2 = result3
        count +=1
