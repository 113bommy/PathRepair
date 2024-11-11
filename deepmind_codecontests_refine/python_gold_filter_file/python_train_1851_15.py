n,d=map(int,input().split())
print(sum(eval("(("+input().replace(" ",")**2+(")+")**2)")**0.5<=d for _ in range(n)))