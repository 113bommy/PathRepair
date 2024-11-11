t = int(input())
n_list = []
s_list = []
for i in range(t):
    n_list.append(int(input()))
    s_list.append(input())

ans = []

for i in range(t):
    n = n_list[i]
    s = s_list[i]
    cnt = 0
    if s[0] == "<":
        if s[-1] == "<":
            ans.append(0)
        else:
            one = 0
            two = 0
            for j in range(n):
                if s[j] == "<":
                    one += 1
                else:
                    break
            for j in range(n):
                if s[-(j+1)] == ">":
                    two += 1
                else:
                    break
            ans.append(min(one, two))

    else:
        ans.append(0)
for a in ans:
    print(a)
