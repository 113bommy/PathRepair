while 1:
    s1 = input().split('"')
    if s1 == ['.']:
        break
    s2 = input().split('"')
    if len(s1) != len(s2):
        print("DIFFERENT")
        continue
    r = [0]*2
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            r[i%2] += 1
    if [0,1]<r:
        print("DIFFERENT")
    else:
        print(["IDENTICAL","CLOSE"][r[1]])