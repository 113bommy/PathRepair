s=input()
t=input()

if s==t:
    print("-1")
elif len(s)==len(t):
    print(len(s))
else:
    print(max(len(s),len(t)))