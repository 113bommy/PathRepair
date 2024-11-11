c=0
n=int(input())
s=input().split()
q=int(input())
t=input().split()
s.sort()

print(len(set(s)&set(t)))
