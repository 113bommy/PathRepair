n, m = map(int, input().split())
s1 = input()
s2 = input()
 
tx = s1[0]+s2[0]+s1[-1]+s2[-1]
 
if tx == "<v>^" or tx == ">^<v":
    print("YES")
 
else:
    print("NO")