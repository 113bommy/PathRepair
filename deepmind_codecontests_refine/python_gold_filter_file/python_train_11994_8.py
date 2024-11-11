t=int(input())
for i in range(t):
    s=input()
    if "aa" in s or "bb" in s or "cc" in s:
        print(-1)
    elif len(s)==1 and s[0]=="?":
        print("a")
    else:
        s=list(s)
        for j in range(len(s)):
            if s[j]=="?":
               if j!=0 and j!=len(s)-1:
                  if s[j-1]!="a" and s[j+1]!="a":s[j]="a"
                  elif s[j-1]!="b" and s[j+1]!="b":s[j]="b"
                  elif s[j-1]!="c" and s[j+1]!="c":s[j]="c"
               elif j==0:
                  if s[j+1]!="a":s[j]="a"
                  elif s[j+1]!="b":s[j]="b"
                  elif s[j+1]!="c":s[j]="c"
               elif j==len(s)-1:
                  if s[j-1]!="a":s[j]="a"
                  elif s[j-1]!="b":s[j]="b"
                  elif s[j-1]!="c":s[j]="c"
        print(*s,sep="")
