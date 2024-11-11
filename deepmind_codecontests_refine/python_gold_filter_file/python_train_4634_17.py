inp = input().strip()
hpos = inp.find('h')
if hpos!=-1:
    epos = inp.find('e', hpos+1)
    if epos!=-1:
        l1pos = inp.find('l', epos+1)
        if l1pos!=-1:
            l2pos = inp.find('l', l1pos+1)
            if l2pos!=-1:
                opos = inp.find('o', l2pos+1)
                if opos!=-1:    print("YES")
                else:   print("NO")
            else:   print("NO")
        else:   print("NO")
    else:   print("NO")
else:   print("NO")