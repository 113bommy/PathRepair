def f(i):
    global cube
    return cube[i-1]
cube=input().split()

if f(1)==f(2) and f(1)==f(3) and f(1)==f(4):
    if f(9)==f(10) and f(9)==f(11) and f(9)==f(12):
        if f(5)==f(6) and f(5)==f(15) and f(5)==f(16):
            if f(13)==f(14) and f(13)==f(23) and f(13)==f(24):
                if f(7)==f(8) and f(7)==f(17) and f(7)==f(18):
                    if f(21)==f(22) and f(21)==f(19) and f(21)==f(20):
                        print ("YES")
                        exit(0)
        if f(13)==f(14) and f(13)==f(7) and f(13)==f(8):
            if f(5)==f(6) and f(5)==f(19) and f(5)==f(20):
                if f(17)==f(18) and f(17)==f(23) and f(17)==f(24):
                    if f(21)==f(22) and f(21)==f(15) and f(21)==f(16):
                        print ("YES")
                        exit(0)
if f(17)==f(18) and f(17)==f(19) and f(17)==f(20):
    if f(13)==f(14) and f(13)==f(15) and f(13)==f(16):
        if f(24)==f(22) and f(24)==f(10) and f(24)==f(12):
            if f(1)==f(3) and f(1)==f(23) and f(1)==f(21):
                if f(5)==f(7) and f(5)==f(2) and f(5)==f(4):
                    if f(9)==f(11) and f(9)==f(6) and f(9)==f(8):
                        print("YES")
                        exit(0)
        if f(24)==f(22) and f(24)==f(2) and f(24)==f(4):
            if f(1)==f(3) and f(1)==f(6) and f(1)==f(8):
                if f(5)==f(7) and f(5)==f(10) and f(5)==f(12):
                    if f(9)==f(11) and f(9)==f(23) and f(9)==f(21):
                        print("YES")
                        exit(0)
if f(5)==f(6) and f(5)==f(7) and f(5)==f(8):
    if f(21)==f(22) and f(21)==f(23) and f(21)==f(24):
        if f(3)==f(4) and f(17)==f(19) and f(10)==f(9) and f(16)==f(14):
            if f(1)==f(2) and f(18)==f(20) and f(12)==f(11) and f(15)==f(13):
                if f(3)==f(18) and f(17)==f(12) and f(10)==f(15) and f(16)==f(1):
                    print("YES")
                    exit(0)
                if f(3)==f(15) and f(17)==f(1) and f(10)==f(18) and f(16)==f(12):
                    print("YES")
                    exit(0)
print("NO")
                
