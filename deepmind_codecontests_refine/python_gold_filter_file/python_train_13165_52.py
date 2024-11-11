a = [2, 7, 2, 3, 3, 4, 2, 5, 1, 2]
#print(len(a))
n = input()
ans = a[(ord(n[0]) - ord('0'))] * a[(ord(n[1]) - ord('0'))]
print(ans)