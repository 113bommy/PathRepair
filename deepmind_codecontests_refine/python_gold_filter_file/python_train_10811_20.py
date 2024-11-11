n,s=int(input()),input()
print(max([s[0:i].count('I')-s[0:i].count('D') for i in range(n+1)]))