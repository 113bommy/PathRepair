length = int(input())

for i in range(length):
    s = input()
    
    ans = 0
    
    for i in range(len(s)):
        if (s[i] == "B" and ans != 0):
            ans -= 1
        else:
            ans += 1
            
    print(ans)       
        
        



