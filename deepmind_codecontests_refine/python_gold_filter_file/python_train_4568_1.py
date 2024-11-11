nums={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
while True:
    try:
        s=input()
    except:
        break
    ans=nums[s[0]]
    for i in range(1,len(s)):
        if nums[s[i-1]]<nums[s[i]]:
            ans+=nums[s[i]]-2*nums[s[i-1]]
        else:
            ans+=nums[s[i]]
    print(ans)
        