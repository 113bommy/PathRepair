n = int(input())
s3=["abb","a.d","ccd"]

s = [["abcc", "abdd", "ddba", "ccba"],
["dccdd", "daa.c", "c..bc", "c..bd", "ddccd"],
["abbc..", "a.ac..", "bba.cc", "a..aab", "a..b.b", ".aabaa"],
["aba....","aba....","bab....","bab....","a..bbaa","a..aabb",".aabbaa"]]
if n == 2:
    print(-1)
elif n == 3:
    [print(x) for x in s3]
else:
    d, m = divmod(n, 4)
    d -= 1
    m += 4
    for i in range(d):
        [print("." * 4 * i + x + "." * (4 * (d - i - 1) + m)) for x in s[0]]
    [print("." * 4 * d + x) for x in s[m - 4]]
