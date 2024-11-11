names = ['Edurounds', 'Flushed', "Orz", 'Yt', 'Ggh', 'Fg', 'Fdg', 'Fdga', 'Fgs', 'sdcv', 'anantcool', 'anantorz', 'bruhone', 'lol', "geniosity", "bruhtwo", "bruhthree", "bruhprime", "twoprime"'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', "anantgh", "eduround", "brickedu", "moorz", "bruh", "qw", "we", "er", "rt"]

names1 = []

for b in names:
    names1.append(b.title())

n, k = map(int, input().split())
p = 0

a = input().split()

res = names1[:n]



for i in range(n-k+1):
    if a[i] == 'NO':
        res[i+k-1] = res[i]

print(*res)


# if a[0] == 'NO':
#     for i in range(k):
#         res.append(names1[p])
# else:
#     for i in range(k):
#         res.append(names1[p])
#         p += 1
# # p += 1
# #print(res)
#
# for i in a[1:]:
#     if i == "NO":
#         res.append(names1[p-1])
#     else:
#         p += 1
#         res.append(names1[p])
#
# # if a[-1] == 'NO':
# #     res.append(names1[p-2])
# # else:
# #     res.append(names1[p])
#
# # if a[-1] == 'NO':
# #     res.append(names1[p-1])
# # else:
# #     res.append(names1[p])
# #
# print(*res, len(res))
