s=input()
w=int(input())
ans=""
for i in range(-1*(len(s)//-w)):
    ans+=s[i*w]
print(ans)
