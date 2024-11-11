n = int(input())
s = input()
t = input()
p = 0           #used as a pointer
dist = 0        #used as hamming distance
m = [[] for i in range(0,26)]
sr = []
while p < len(s):
    #print('...1')
    if s[p] != t[p]:
        m[ord(s[p])-ord('a')].append((t[p], p))
        dist += 1
    p += 1

#print(m)
p = 0
while p < len(s):
    #print('...2')
    if s[p] != t[p]:
        flag = False
        for i in sr:
            if i[0] == s[p] and i[1] == t[p]:
                flag = True
                break
        if flag == True:
            p += 1
            continue
        sr.append((s[p], t[p]))
        for i in m[ord(t[p]) - ord('a')]:
            if i[0] == s[p]:
                dist -= 2
                print(dist)
                print(p+1, i[1]+1)
                quit()
    p += 1

p = 0
while p < len(s):
    #print('...3')
    if s[p] != t[p]:
        if len(m[ord(t[p]) - ord('a')]) > 0:
            dist -= 1
            print(dist)
            print(p+1, m[ord(t[p]) - ord('a')][0][1]+1)
            quit()
    p += 1
print(dist)
print(-1, -1)