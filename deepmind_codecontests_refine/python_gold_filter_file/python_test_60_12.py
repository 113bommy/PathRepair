# C. Delete Two Elements

from sys import stdin, stdout
input = stdin.readline
print = stdout.write

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    k = sum(a)/n
    
    counts = dict()
    for i in a:
        counts[i] = counts.get(i, 0) + 1
    
    numbers = sorted(counts.keys())
    
    point1, point2 = 0, len(numbers)-1
    
    ans = 0
    
    while point2 >= point1:
        num1 = numbers[point1]
        num2 = numbers[point2]
        
        if num1+num2 > 2*k: point2 -= 1
        elif num1+num2 < 2*k: point1 +=1
        else:
            if num1 != num2: ans += counts[num1]*counts[num2]
            else: ans += (counts[num1]**2-counts[num1])//2
            
            point2 -= 1
            point1 += 1
    
    print(str(ans)+"\n")