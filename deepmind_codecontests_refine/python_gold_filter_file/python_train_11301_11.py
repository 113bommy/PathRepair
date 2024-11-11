inputLine=input()
lineSplit=inputLine.split()
sonyaStart=int(lineSplit[0])
sonyaEnd=int(lineSplit[1])
filyaStart=int(lineSplit[2])
filyaEnd=int(lineSplit[3])
sonyaPlink=int(lineSplit[4])

if sonyaStart<=filyaStart:
    if sonyaEnd<filyaStart:
        meetingTime=0
    #print("sonyaStart<filyaStart")
    elif filyaEnd<sonyaEnd:
        #print("filyaEnd<sonyaEnd")
        meetingTime=filyaEnd-filyaStart+1

        if sonyaPlink in range(filyaStart,filyaEnd+1):
            meetingTime-=1
            #print("sonyaPlink in range(filyaStart,filyaEnd)")

    else:
        #print("filyaEnd>sonyaEnd")
        meetingTime=sonyaEnd-filyaStart+1

        if sonyaPlink in range(filyaStart,sonyaEnd+1):
            #print("sonyaPlink in range(filyaStart,sonyaEnd)")
            meetingTime-=1

elif filyaStart<=sonyaStart:
    if filyaEnd<sonyaStart:
        meetingTime=0
    #print("filyaStart<filyaEnd")
    elif sonyaEnd<filyaEnd:
        #print("sonyaEnd<filyaEnd")
        meetingTime=sonyaEnd-sonyaStart+1

        if sonyaPlink in range(filyaStart, sonyaEnd+1):
            meetingTime -= 1
            #print("sonyaPlink in range(sonyaStart, sonyaEnd)")

    else:
        #print("sonyaEnd>filyaEnd")
        meetingTime=filyaEnd-sonyaStart+1

        if sonyaPlink in range(sonyaStart, filyaEnd+1):
            meetingTime -= 1
            #print("sonyaPlink in range(sonyaStart, filyaEnd)")

print(meetingTime)
