s=input()
cnt=s.count("VK")
s=s.replace("VK"," ")
if 'VV' in s or 'KK' in s:
    cnt += 1
print(cnt)