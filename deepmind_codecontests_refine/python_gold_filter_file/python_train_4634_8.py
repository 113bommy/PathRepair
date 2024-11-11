import re
msg = input()
if(re.search("h.*e.*l.*l.*o",msg)):
    print("YES")
else:
    print("NO")