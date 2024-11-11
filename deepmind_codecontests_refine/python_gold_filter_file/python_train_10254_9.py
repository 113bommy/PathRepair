def fu(s):
    n=len(s)
    #print(n % 2)
    if n % 2:
        return s
    a= fu(s[:n// 2])
    b = fu(s[n//2 :])
    if a < b:
        return a + b
    else:
        return b + a
    
 
a= fu(input())
b = fu(input())
#print(a, b)
 
if a == b:
    print("YES")
else:
    print("NO")