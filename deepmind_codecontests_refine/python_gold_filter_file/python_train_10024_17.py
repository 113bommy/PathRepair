n = int(input()) 
num = [ i for i in map(int, input().split())] 
ans = 0
ans += num.index(max(num))
temp = list(reversed(num)) 
ans += temp.index(min(temp))
if  num.index(max(num)) > len(temp) -  temp.index(min(temp)) - 1:
    ans -= 1
print(ans)