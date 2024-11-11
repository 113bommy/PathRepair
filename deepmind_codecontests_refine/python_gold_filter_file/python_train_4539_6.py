s=input()
cnt=s.count("VK")
s1=s.replace("VK","1")
if "VV" in s1 or "KK" in s1:
    cnt+=1
print(cnt)