for _ in range(int(input())):
 a,b=map(int,input().split())
 print(abs(b-a)//10+bool(abs(b-a)%10))