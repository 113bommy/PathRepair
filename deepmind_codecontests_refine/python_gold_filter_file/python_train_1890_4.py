s=input()
x=(len(s)-s.count('a'))//2
t=s[len(s)-x:]
if s[:len(s)-x].replace('a','')==t:
    print(s[:len(s)-x])
else: print(":(")


    