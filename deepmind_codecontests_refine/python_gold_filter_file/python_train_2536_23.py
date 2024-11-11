import re
s = input().strip()
pattern1 = re.compile("http[a-z]+?ru")
pattern2 = re.compile("ftp[a-z]+?ru")
if pattern1.match(s)!=None:
    end = pattern1.match(s).span()[1]
    if end!=len(s):
        print("http://"+s[4:end-2]+".ru/"+s[end:])
    else:
        print("http://"+s[4:end-2]+".ru")
if pattern2.match(s)!=None:
    end = pattern2.match(s).span()[1]
    if end!=len(s):
        print("ftp://"+s[3:end-2]+".ru/"+s[end:])
    else:
        print("ftp://"+s[3:end-2]+".ru")
