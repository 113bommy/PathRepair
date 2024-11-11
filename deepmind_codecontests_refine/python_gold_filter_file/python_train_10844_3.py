n = int(input().strip())
while n > 0:
    s = input()
    t = input()
    ls = [(s[0], 1)]
    for i in range(1, len(s)):
        if(s[i] == s[i-1]):
            ls[-1] = (s[i], ls[-1][1]+1)
        else:
            ls.append((s[i], 1))
    vs = [(t[0], 1)]
    c  = 0
    flag = 1
    for i in range(1, len(t)):
        if(t[i] == t[i-1]):
            vs[-1] = (t[i], vs[-1][1]+1)
        else:
            if(c < len(ls)):
                if((ls[c][0] == vs[c][0]) and ((ls[c][1] <= vs[c][1]))):
                    vs.append((t[i], 1))
                    c+=1
                else:
                    flag = 0
                    break
            else:
                flag = 0
                break
    if(flag == 1 and (ls[-1][0] == vs[-1][0]) and ((ls[-1][1] <= vs[-1][1])) and len(vs) == len(ls)):
        print("YES")
    else:
        print("NO")
    n-=1
