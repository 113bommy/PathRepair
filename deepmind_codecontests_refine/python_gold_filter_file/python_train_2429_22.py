n = int(input())
s = input()
first = [int(x) for x in s[:n]]
second = [int(x) for x in s[n:]]

if (max(sum(first),sum(second)) - min(sum(first),sum(second))) < n:
    print ("NO")
    exit()
else:
    if sum(first)<sum(second):
        first,second = second,first
    first = sorted(first)
    second = sorted(second)
    for x in range(n):
        if first[x]<=second[x]:
            print ("NO")
            exit()
print ("YES")